/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:51:28 by kiwasa            #+#    #+#             */
/*   Updated: 2025/04/22 19:08:33 by kiwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; ++i)
	{
		for (int j = 0; argv[i][j] != '\0'; ++j)
		{
			std::cout << (char)std::toupper(argv[i][j]);
		}
		std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}
