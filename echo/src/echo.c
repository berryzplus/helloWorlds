/* Copyright (C) 2013 Minato Hamano
 *
 * This program is free software:
 * you can redistribute it and/or modify it under the terms of
 * the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string.h>
#include <stdio.h>

#ifndef BUFF_SIZE
# define BUFF_SIZE 1024
#endif

int main(int argc, char* argv[]) {

    char buff[BUFF_SIZE + 1];

    if (1 < argc && argv[1][0] != 0) {
        size_t len = strlen(argv[1]);
        strncpy(buff, argv[1], (len < BUFF_SIZE) ? len : BUFF_SIZE);
    }
    else {
        fgets(buff, BUFF_SIZE, stdin);
    }

    printf(buff);

    return 0;
}

