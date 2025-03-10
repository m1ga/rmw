/*
This file is part of rmw<https://remove-to-waste.info/>

Copyright (C) 2012-2022  Andy Alt (arch_stanton5995@protonmail.com)
Other authors: https://github.com/theimpossibleastronaut/rmw/blob/master/AUTHORS.md

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _INC_PURGING_H
#define _INC_PURGING_H

#include <sys/stat.h>
#include <unistd.h>             /* for rmdir() */

#include "time_rmw.h"
#include "config_rmw.h"

#define LEN_MAX_RM_CMD (LEN_MAX_PATH + 128 + LEN_MAX_PATH)
#define ONEFS_STR "--one-file-system"
typedef struct
{
  char full_path[LEN_MAX_PATH];
  char onefs[sizeof ONEFS_STR];
  char v[3];
} st_rm;

bool is_time_to_purge(st_time * st_time_var, const char *file);

void init_rm(st_rm * rm);

int
purge(st_config * st_config_data,
      const rmw_options * cli_user_options,
      st_time * st_time_var, int *orphan_ctr);

short orphan_maint(st_waste * waste_head, st_time * st_time_var,
                   int *orphan_ctr);
#endif
