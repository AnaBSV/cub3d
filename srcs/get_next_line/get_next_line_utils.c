#include "../../includes/get_next_line.h"

int	endof_line(char *backup)
{
	int	i;

	i = 0;
	if (backup == NULL)
		return (0);
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

