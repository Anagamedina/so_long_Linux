/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:28:11 by anamedin          #+#    #+#             */
/*   Updated: 2024/09/03 19:45:14 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <stdarg.h>

/* ************************************************************************** */
/*                                 MEMORY                                     */
/* ************************************************************************** */

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);

/* ************************************************************************** */
/*                                 STRING                                     */
/* ************************************************************************** */

char			*ft_itoa(int n);
char			**ft_split(const char *s, char c);
size_t			ft_strlen(char const *str);
/* ************************************************************************** */
/*                                 PRINTF                                     */
/* ************************************************************************** */
int				ft_printf(char const *format, ...);
int				ft_putchar(char c);
int				ft_putnbr(long n);
int				ft_print_string(char *str);
int				ft_hex(unsigned long nbr, const char str);
unsigned int	ft_unsignedint(unsigned int n);

/*---------------------------------GETNEXTLINE--------------------------------*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

size_t			ft_strlen(const char *str);

#endif
