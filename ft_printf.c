/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aenrique <aenrique@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:12:22 by aenrique          #+#    #+#             */
/*   Updated: 2022/09/12 22:17:59 by aenrique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdarg.h>

int	ft_putchar(char	c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		i = 0;
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
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
		len += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else
		len += ft_putchar(n + 48);
	return (len);
}

int	ft_puthex(unsigned int nbr, char *base)
{
	int		count;

	count = 0;
	if (nbr >= 16)
	{
		count += ft_puthex(nbr / 16, base);
		count += ft_putchar(base[nbr % 16]);
	}
	else
		count += ft_putchar(base[nbr % 16]);
	return (count);
}

int	ft_eval(va_list arg, const char *input, int i)
{
	int 	len;

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
	int			i;
	int			len;
	va_list		arg;

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
	  ft_printf("Hola\n");
	  ft_printf("Hola  %d \n", 1234);
	  ft_printf("Hola  %x \n", 15);
	  ft_printf("Hola  %s \n", "POPEYE");
	return (0);
}
