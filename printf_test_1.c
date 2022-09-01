/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenrique <aenrique@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:25:15 by aenrique          #+#    #+#             */
/*   Updated: 2022/09/01 08:25:21 by aenrique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdarg.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return(0);
}

int	ft_putstr(char *str)
{
	int i;
	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	long long	n;
	int			len;

	len = 0;
	n = nb;
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if(n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else
		len += ft_putchar	(n + 48);
	return (len);
}

int	ft_puthex(unsigned int nbr, char *base)
{
	unsigned int	size;
	int				count;

	count = 0;
	size = 16;
	if (nbr >= size)
	{
		count += ft_puthex(nbr / size, base);
		count += ft_putchar(base[nbr % size]);
	}
	else
		count += ft_putchar(base[nbr % size]);
	return (count);
}

int	ft_eval(va_list arg, const char *input, int i)
{
	int	len;

	len = 0;
	if (input[i] == 's')
		len += ft_putstr(va_arg(arg, char *));
	if (input[i] == 'd')
		len += ft_putnbr(va_arg(arg, int));
	if (input[i] == 'x')
		len += ft_puthex(va_arg(arg, unsigned int), "0123456789abcdef");
	return (len);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	int 	len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, input);
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			len += ft_eval(arg, input, i + 1);
			i++;
		}
		else
		{
			ft_putchar(input[i]);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}

int	main(void)
{
	ft_printf("Hola  %d  %s  %x   R\n", -1234, "POPEYE", 15);
	ft_printf("Hola  %d  %s  %x   R\n", 1234, "% ˆ &%#", 16);
	ft_printf("Hola  %d  %s  %x   R\n", 1234, "       ", 9);
	ft_printf("Hola  %d  %s  %x   R\n", 1234, "mAm 232", 10);
	return (0);
}
