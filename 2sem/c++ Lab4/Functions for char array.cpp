void* Memcpy(void* s1, const void* s2, size_t n)
{
	if (s1 == nullptr || s2 == nullptr || n <= 0) 
		return NULL;
	char* temp_s1 = (char*)s1;
	const char* temp_s2 = (const char*)s2;
	for (int i = 0; i < n; i++)
		temp_s1[i] = temp_s2[i];
	return s1;
}

void* Memmove(void* s1, const void* s2, size_t n)
{
	if (s1 == nullptr || s2 == nullptr || n <= 0)
		return NULL;
	char* temp_s1 = (char*)s1;
	const char* temp_s2 = (const char*)s2;
	char* temp = new char[n];
	for (int i = 0; i < n; i++)
		temp[i] = temp_s2[i];
	for (int i = 0; i < n; i++)
		temp_s1[i] = temp[i];
	delete[] temp;
	return s1;
}

char* Strcpy(char* s1, const char* s2)
{
	if (s1 == nullptr || s2 == nullptr)
		return NULL;
	char* temp_s1 = s1;
	while (*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
	return temp_s1;
}

char* Strncpy(char* s1, const char* s2, size_t n)
{
	if (s1 == nullptr || s2 == nullptr)
		return NULL;
	char* temp_s1 = s1;
	while (*s2 != '\0' && n--)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
	return temp_s1;
}

char* Strcat(char* s1, const char* s2)
{
	int i, j;
	char* temp_s1 = s1;
	for (i = 0; s1[i] != '\0'; i++);
	for (j = 0; s2[j] != '\0'; j++)
		s1[i + j] = s2[j];
	s1[i + j] = '\0';
	return temp_s1;
}

char* Strncat(char* s1, const char* s2, size_t n)
{
	char* temp_s1 = s1;
	int i, j = 0;
	for (i = 0; s1[i] != '\0'; i++);
	while (s2[j] != '\0' && n--)
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return temp_s1;
}

int Memcmp(const void* s1, const void* s2, size_t n)
{
	const char* temp_s1 = (const char*)s1;
	const char* temp_s2 = (const char*)s2;
	int a, b;
	for (int i = 0; i < n; i++) 
	{
		a = (int)temp_s1[i];
		b = (int)temp_s2[i];
		if ((a < b) || (a > b))
			return (a - b);
	}
	return 0;
}

int Strcmp(const char* s1, const char* s2)
/*Нулевое значение говорит о том, что обе строки равны.
Значение больше нуля указывает на то, что строка string1 больше строки string2, значение меньше нуля свидетельствует об обратном.
Функция strcmp начинает сравнивать по одному символу и как только будут найдены первые неодинаковые символы, чей код окажется больше, та строка и будет считаться большей.*/
{
	int temp = 0;
	while (!(temp = *(unsigned char*)s1 - *(unsigned char*)s2) && *s1)
	{
		s1++;
		s2++;
	}
	if (temp < 0)
		return -1;
	else if (temp > 0)
		return 1;
	return 0;
}

int Strcoll(const char* s1, const char* s2)
{
	int temp = 0;
	while (!(temp = *(unsigned char*)s1 - *(unsigned char*)s2) && *s1)
	{
		s1++;
		s2++;
	}
	if (temp < 0)
		return -1;
	else if (temp > 0)
		return 1;
	return 0;
}

int Strncmp(const char* s1, const char* s2, size_t n)
{
	int temp = 0;
	while (*s1 != '\0' && *s2 != '\0' && n && !(temp = *(unsigned char*)s1 - *(unsigned char*)s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (temp < 0)
		return -1;
	else if (temp > 0)
		return 1;
	return 0;
}

/*size_t Strxfrm(char* s1, const char* s2, size_t n)
{

}*/

char* Strtok(char* s1,  char* s2)
{
	static char* input = NULL;
	if (s1 != NULL)
		input = s1;
	if (input == NULL)
		return NULL;

	char* result = new char[strlen(input) + 1];
	int i = 0;

	for (; input[i] != '\0'; i++) 
	{
		if (input[i] != *s2)
			result[i] = input[i];

		else 
		{
			result[i] = '\0';
			input = input + i + 1;
			return result;
		}
	}
	result[i] = '\0';
	input = NULL;
	return result;
}

void* Memset(void* s, int c, size_t n)
{
	unsigned char* s_temp = (unsigned char*)s;
	while (n--)
	{
		*s_temp++ = (char)c;
	}
	return s;
}

//char* Strerror(int errnum)
//{
//}

size_t Strlen(const char* str)
{
	int size = 0;
	if (str != NULL)
	{
		while (*(str + size) != '\0')
			++size;
	}
	return size;
}

