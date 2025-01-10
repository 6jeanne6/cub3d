/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:33:16 by jewu              #+#    #+#             */
/*   Updated: 2025/01/10 16:33:35 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//to remain in 0-2π field(trigonometric circle)
double	normal_angle(double angle)
{
	if (angle < 0)
		angle += 2 * PI;
	else if (angle > (2 * PI))
		angle -= 2 * PI;
	return (angle);
}
