#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

static int write_stdout(const char *token, int length)
{
	int rc;
	int bytes_written = 0;

	do {
		rc = write(1, token + bytes_written, length - bytes_written);
		if (rc < 0)
			return rc;

		bytes_written += rc;
	} while (bytes_written < length);

	return bytes_written;
}

// functia pentru printarea unui integer
void print_integer(char *out_string, int *out_size, va_list args) {
	// printed_integer este int-ul care trebuie printat 
	int printed_integer;
	// uinteger este un auxiliar pe care il folosesc pentru
	// a printa int-ul. Ma ajuta in cazul in care numarul care
	// trebuie printat este negativ
	unsigned int uinteger;
	// numarul il sparg in cifre pe care le adaug in vector,
	// iar elementele din vector le adaug in ordinea corespunzatoare
	// in out_string si incrementez *out_size, v_length defineste lungimea
	// vectorului
	int vector[100], v_length = 0, j;

	// citesc argumentul
	printed_integer = va_arg(args, int);
	
	// Aici verific daca argumentul este negativ, caz in care
	// printez un '-', iar uinteger devine acel numar, dar cu plus.
	// Daca printed_integer este pozitiv atunci uinteger ia valoarea
	// lui printed_integer.
	if (printed_integer < 0) {
		out_string[*out_size] = '-';
		(*out_size)++;
		uinteger = -printed_integer;
	} else {
		uinteger = printed_integer;
	}
	// In acest while sparg uinteger in cifre si le adaug in vector
	// Acestea vor fi puse insa in ordine inversa in vector
	while (uinteger != 0) {
		vector[v_length] = uinteger % 10;
		v_length++;
		uinteger = uinteger / 10;
	}
	// aici adaug in ordinea corespunzatoare elementele din vector
	// in out_string
	for (j = 0; j < v_length; j++) {
		out_string[*out_size] = vector[v_length - 1 - j] + '0';
		(*out_size)++;
	}
}

// functia pentru printarea unui unsigned
void print_unsigned(char *out_string, int *out_size, va_list args) {
	// citesc numarul direct intr-un unsigned int
	unsigned int uinteger;
	// vector auxiliar ca la functia precedenta, folosit cu
	// acelasi scop, impreuna cu lungimea v_length si iteratorul j
	int vector[100], v_length = 0, j;

	// aici citesc unsigned-ul care trebuie printat
	uinteger = va_arg(args, int);

	// In acest while sparg uinteger in cifre si le adaug in vector
	// Acestea vor fi puse insa in ordine inversa in vector
	while(uinteger != 0) {
		vector[v_length] = uinteger % 10;
		v_length++;
		uinteger = uinteger / 10;
	}
	// aici adaug in ordinea corespunzatoare elementele din vector
	// in out_string
	for (j = 0; j < v_length; j++) {
		out_string[*out_size] = vector[v_length - 1 - j] + '0';
		(*out_size)++;
	}
}

// in aceasta functie printez numarul in hexazecimal
void print_hex(char *out_string, int *out_size, va_list args) {
	// voi citi numarul pe care trebuie sa il reprezint in hexa
	// ca pe un unsigned, deoarece nu va fi diferita reprezentarea
	// sa in hexa
	unsigned int nr_hex;
	// urmatoarele variabile sunt folosite pentru a forma numarul
	// in hexa. Rest este folosit pentru a forma caracterul in hexa
	// care trebuie adaugat in out_string
	// auxiliary string este folosit la fel ca vector in functiile
	// anterioare pentru a adauga elementele in out_string in ordinea
	// ceruta. auxstr_int este lungimea lui auxiliary_string.
	int rest;
	char character_added;
	char auxiliary_string[8];
	int auxstr_int = 0;

	// aici citim integerul ca un unsigned integer pe care il
	// reprezentam ca un hexa
	nr_hex = va_arg(args, unsigned int);
	// in acest while formez auxiliary string, dar acesta
	// stocheaza caracterele numarului in hexa in ordine inversa
	while(nr_hex != 0) {
		// folosesc impartirea repetata la 16
		rest = nr_hex % 16;
		if (rest == 10)
			character_added = 'a';
		if (rest == 11)
			character_added = 'b';
		if (rest == 12)
			character_added = 'c';
		if (rest == 13)
			character_added = 'd';
		if (rest == 14)
			character_added = 'e';
		if (rest == 15)
			character_added = 'f';
		if (rest >= 0 && rest <= 9)
			character_added = rest + '0';
		// aici adaug in auxiliary_string
		auxiliary_string[auxstr_int] = character_added;
		auxstr_int++;
		nr_hex = nr_hex / 16;
	}
	// acum adaug caracterele din auxiliary_string in ordinea buna
	// in out_string
	auxiliary_string[auxstr_int] = '\0';
	for (int j = 0; j < strlen(auxiliary_string); j++) {
		out_string[*out_size] = auxiliary_string[strlen(auxiliary_string) - 1 - j];
		(*out_size)++;
	}
}

// functia pentru printarea unui char
void print_char(char *out_string, int *out_size, va_list args) {
	// aici citesc caracterul
	int character;

	// stochez codul ASCII al caracterului
	character = va_arg(args, int);
	// adaug in out_string
	out_string[*out_size] = character;
	(*out_size)++;
}

// functia pentru printarea unui string
static void print_string(char *out_string, int *out_size, va_list args) {
	int j;
	// folosesc un char* pentru un argument de tip string
	char* argument_string = NULL;

	// aici citesc arguentul char*
	argument_string = va_arg(args, char*);
	// aici adaug fiecare caracter din string_argument
	for (j = 0; j < strlen(argument_string); j++) {
		out_string[*out_size] = argument_string[j];
		(*out_size)++;
	}
}

int iocla_printf(const char *format, ...)
{
	// i si j sunt iteratorii prin loop-urile for
	int i, j;
	// O sa fac un char* pe nume out_string pe care il folosesc
	// in write_stdout, out_size reprezinta lungimea acestui string,
	// pe care o incrementez la fiecare pas
	int out_size = 0;
	char *out_string = malloc((strlen(format) * 3) * sizeof(char));
	
	// ok il foloesc ca sa verific printarea lui %
	int ok = 0;

	// secventa de cod pentru a obtine argumentele
	va_list args;
	va_start(args, format);

	// aici verific primul element din string-ul format
	// si il adaug in out_string daca este diferit de %
	if (format[0] != '%')
		out_string[out_size++] = format[0];
	// in acest for verific fiecare caracter din format
	for (i = 0; i < strlen(format) - 1; i++) {
		// repeat_if_found este un label pe care il folosesc pentru
		// a reitera secventa urmatoare de cod in cazul in care
		// intalnesc un caracter '%' 
repeat_if_found:
		// aici printez un caracter in cazul in care nu este precedat
		// de un '%''
		if (format[i - 1] != '%' && i != 0 && format[i] != '%') {
			out_string[out_size] = format[i];
			out_size++;
		}
		// daca avem o secventa para de '%' atunci deja am printat
		// caracterele %, iar ceea ce urmeaza dupa nu se considera
		// ca ar trebui considerat argument, caz in care se adauga
		// caracterul dat ca atare
		if (format[i] != '%' && ok == 1 && format[i - 1] == '%') {
			ok = 0;
			out_string[out_size] = format[i];
			out_size++;
		}
		// daca ne aflam pe un caracter care este '%'
		// intram pe acest if
		if (format[i] == '%') {
			// prima oara verificam daca urmeaza o secventa de
			// caractere de tip '%'
			if (format[i + 1] == '%') {
				int number = 1;
				while(format[i + number] == '%') {
					number++;
				}
				if (number != 1) {
					if (number % 2 == 0) {
						i = i + number;
						for (j = 0; j < number / 2; j++) {
							out_string[out_size] = '%';
							out_size++;
						}
						ok = 1;
					} else {
						for (j = 0; j < (number - 1)/ 2; j++) {
							out_string[out_size] = '%';
							out_size++;
						}
						i = i + number - 1;
						ok = 0;
					}
					goto repeat_if_found;
				}
			}
			// acum verificam daca dupa acel caracter '%'
			// avem caractere ca d, u, c, x, s, caz in care
			// va trebui sa printam argumentul dat
			// aici apelez functia de printare int
			if (format[i + 1] == 'd') {
				print_integer(out_string, &out_size, args);
			}
			// aici apelez functia de printare unsigned
			if (format[i + 1] == 'u') {
				print_unsigned(out_string, &out_size, args);
			}
			// aici apelez functia de printare char
			if (format[i + 1] == 'c') {
				print_char(out_string, &out_size, args);
			}
			// aici apelez functia de printare hexa
			if (format[i + 1] == 'x') {
				print_hex(out_string, &out_size, args);
			}
			// aici apelez functia de printare char* (string)
			if (format[i + 1] == 's') {
				print_string(out_string, &out_size, args);
			}
		}
	}
	// daca penultimul element este diferit de %, atunci
	// adaug ultimul element si pun terminatorul sirului
	// altfel pun doar terminatorul de sir, deoarece inseamna
	// ca ultimul element reprezenta impreuna cu % un argument
	if (format[strlen(format) - 2] != '%') {
		out_string[out_size] = format[strlen(format) - 1];
		out_string[++out_size] = '\0';
	} else {
		out_string[out_size] = '\0';
	}
	// aici apelez functia de write_stdout
	write_stdout(out_string, strlen(out_string));
	va_end(args);
	// returnez lungimea sirului daca exista sirul
	int n = strlen(out_string);
	if (n > 0) {
		free(out_string);
		return n;
	}
	return -1;
}
