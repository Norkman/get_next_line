/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:07:53 by nle-bret          #+#    #+#             */
/*   Updated: 2021/12/07 13:11:50 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void Func() {
  static int x = 0;
  // |x| is initialized only once across five calls of |Func| and the variable
  // will get incremented five times after these calls. The final value of |x|
  // will be 5.
  x++;
  printf("%d\n", x);  // outputs the value of |x|
}

int main() {
  Func();  // prints 1
  Func();  // prints 2
  Func();  // prints 3
  Func();  // prints 4
  Func();  // prints 5

  return 0;
}
