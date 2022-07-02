	char	*str;
	int		digits;
	int		n2;

	if (n < 0)
		return (ft_itoaneg((unsigned int) (n * -1)));
	digits = 0;
	n2 = n;
	while (n2 >= 10){
		n2 /= 10;
		digits++;
	}
	digits++;
	str = (char *) malloc ((digits + 1) * sizeof(int));
	if (str) {
		str[digits] = '\0';
		while (--digits != -1){
			str[digits] = (n % 10) + '0';
			n /= 10;
		}
		return (str);
	}
	return (0);