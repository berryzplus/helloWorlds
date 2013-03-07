/* Copyright (C) 2013 Minato Hamano
 *
 * This file is a part of mingwpath.
 *
 * The mingwpath is free software:
 * you can redistribute it and/or modify it under the terms of
 * the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * The mingwpath is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#if HAVE_CONFIG_H
#include "config.h"
#endif

#ifndef _TCHAR_H_
#include <tchar.h>
#endif

#ifndef _WINDOWS_H
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif


int _tmain(int argc, TCHAR* argv[]) {

	int n;
	TCHAR pszPathIn[MAX_PATH + 1];

	if (1 < argc) {
		for (n=1 ; n<argc; n++) {
		}
	}
	/* mode piped input. */
	else if (0 < _filelengthi64(STDIN_FILENO)) {
        _fgetts(pszPathIn, sizeof(pszPathIn), stdin);
	}
	/* no input. */
	else {
		_ftprintf(stderr, _T(PACKAGE_NAME) _T(": no input."));
		return 1;
	}

    return 0;
}

/* for standard __MINGW32__ code. */
#if __MINGW32__ && _UNICODE && !defined(wmain)

int main(int argc, char* argv[]) {

	int result = 0;
	int numArgs = 0;
	LPWSTR *lpwszArgs = NULL;

	lpwszArgs = CommandLineToArgvW(GetCommandLineW(), &numArgs);

	result = _tmain(numArgs, lpwszArgs);

	LocalFree(LocalHandle(lpwszArgs));

	return result;
}

#endif

