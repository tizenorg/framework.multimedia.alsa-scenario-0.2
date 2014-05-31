/*
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 *  Copyright (C) 2008-2009 SlimLogic Ltd
 *  Authors: Liam Girdwood <lrg@slimlogic.co.uk>
 *           Stefan Schmidt <stefan@slimlogic.co.uk>
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "ascenario.h"

#define OP_LIST 1
#define OP_SET  2

#if 0
void print_usage(char *name) {
	printf("Usage: %s <cmd> [<scenario>]\n"
	       " list  - list available scenarios\n"
	       " set <name> - apply scenario <name>\n\n", name);
}

int main(int argc, char *argv[])
{
	struct snd_scenario *scn;
	int num, i, op = 0, err, ret = 0;
	const char **list;

	if(argc > 2) {
		if(!strcmp(argv[1], "set"))
			op = OP_SET;
	} else if(argc > 1) {
		if(!strcmp(argv[1], "list"))
			op = OP_LIST;
	}

	if(!op) {
		print_usage(argv[0]);
		exit(1);
	}

	/* open library */
	scn = snd_scenario_open("default");
	if (scn == NULL) {
		printf("%s: failed to init\n", argv[0]);
		return 0;
	}

	switch (op) {
	case OP_LIST:
		/* get list of scenarios */
		num = snd_scenario_list(scn, &list);
		if (num) {
			for(i = 0 ; i < num ; i++)
				printf("%s\n", list[i]);
		} else {
			printf("%s: no scenarios\n", argv[0]);
			ret = 2;
		}
	break;
	case OP_SET:
		err = snd_scenario_set_scn(scn, argv[2]);
                if (err < 0) {
                        printf("failed to set scenario: %s\n", argv[2]);
			ret = 3;
		}
	break;
	default:
		print_usage(argv[0]);
	break;
	}

	snd_scenario_close(scn);
	return ret;
}

#endif

#if 0
void print_usage(char *name) {
	printf("Usage: %s <card> <cmd> [<scenario>]\n"
	       " <card> list  - list available scenarios\n"
	       " <card> set <name> - apply scenario <name>\n\n", name);
}

int main(int argc, char *argv[])
{
	struct snd_scenario *scn;
	int num, i, op = 0, err, ret = 0;
	const char **list;
	char card[20];

	if(argc > 2) {
		strcpy(card, argv[1]);
	}

	if(argc > 3) {
		if(!strcmp(argv[2], "set"))
			op = OP_SET;
	} else if(argc > 2) {
		if(!strcmp(argv[2], "list"))
			op = OP_LIST;
	}

	if(!op) {
		print_usage(argv[0]);
		exit(1);
	}

	/* open library */
#if 0
	scn = snd_scenario_open("default");
#else
	scn = snd_scenario_open(card);
#endif
	if (scn == NULL) {
		printf("%s: failed to init\n", argv[0]);
		return 0;
	}

	switch (op) {
	case OP_LIST:
		/* get list of scenarios */
		num = snd_scenario_list(scn, &list);
		if (num) {
			for(i = 0 ; i < num ; i++)
				printf("%s\n", list[i]);
		} else {
			printf("%s: no scenarios\n", argv[0]);
			ret = 2;
		}
	break;
	case OP_SET:
		err = snd_scenario_set_scn(scn, argv[3]);
                if (err < 0) {
                        printf("failed to set scenario: %s\n", argv[3]);
			ret = 3;
		}
	break;
	default:
		print_usage(argv[0]);
	break;
	}

	snd_scenario_close(scn);
	return ret;
}
#endif

int main(int argc, char *argv[])
{
	struct snd_scenario *scn;
	int num, i, op = 0, err, ret = 0;
	const char **list;
	char card[20];
        int j;

     for(j = 0 ; j < 100; j++ ) {
	/* open library */
	scn = snd_scenario_open("default");
	if (scn == NULL) {
		printf("%s: failed to init\n", argv[0]);
		return 0;
	}

	/* get list of scenarios */
	num = snd_scenario_list(scn, &list);
#if 0
	for(i = 0 ; i < num ; i++) {
	       err = snd_scenario_set_scn(scn, list[i]);
	       if (err < 0) {
		    printf("failed to set scenario: %s\n", argv[3]);
		    ret = 3;
	       }
        }
#endif
	snd_scenario_close(scn);
     }

     return ret;
}
