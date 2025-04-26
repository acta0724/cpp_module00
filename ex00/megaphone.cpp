/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiwasa <kiwasa@student.42.jp>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:51:28 by kiwasa            #+#    #+#             */
/*   Updated: 2025/04/26 23:13:51 by kiwasa           ###   ########.fr       */
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
		std::string word = argv[i];
		for (std::size_t j = 0; j < word.size(); ++j)
		{
			std::cout << static_cast<char>(std::toupper(argv[i][j]));
		}
		std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}
