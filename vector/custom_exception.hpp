/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_exception.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouib <adouib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 22:03:34 by adouib            #+#    #+#             */
/*   Updated: 2022/12/30 09:59:31 by adouib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

#ifndef CUSTOM_EXCEPTION_H
#define CUSTOM_EXCEPTION_H

namespace ft
{

	struct negative_number_custom_exception : public std::exception
	{
		const char* what() const throw()
		{
			return "Error : size or index requested must not be a negative value";
		}
	};

	struct exceeded_container_limits_custom_exception : public std::exception
	{
		const char* what() const throw()
		{
			return "Error : index requested larger than the container(elements) size (occupied slots)";
		}
	};

	struct exceeded_max_size_custom_exception : public std::exception
	{
		const char* what() const throw()
		{
			return "Error : size requested is greater than the maximum size of the container";
		}
	};

	struct storage_empty_custom_exception : public std::exception
	{
		const char* what() const throw()
		{
			return "Error : the container is  empty and size equals zero";
		}
	};

}

#endif
