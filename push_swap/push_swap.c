//
// Created by Ben Dudley on 2019-07-08.
//

int		ft_atoi(const char *str)
{
	long	i;
	long	off;
	int		flag;
	long	lim;

	i = 0;
	flag = 1;
	while (*str == '\n' || *str == '\t' || *str == ' '
		   || *str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
		flag = -1;
	off = flag == 1 ? INT_MAX : INT_MIN;
	lim = -(off % 10);
	off /= flag * 10;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (i * flag > off || (flag * i == off && (*str - '0') > lim))
			return (0);
		i = i * 10 + flag * (*str - '0');
		str++;
	}
	if (*str != '/0')
		i = 0;
	return (i);
}

int main(int argc, char *argv[])
{
	long num;
	int i;

	if (argc > 1)
	{
		i = 1;
		while (i <= argc - 1)
		{
			num = number(argv[i]);
			if ((num == 0 && *argv[i] != '0') || num > INT_MAX || num < INT_MIN)
		}

	}
	return (0);
}