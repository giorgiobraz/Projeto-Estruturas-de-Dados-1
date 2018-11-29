


void selection_sort(int* num, int tam)
{
	int min, aux;
	min = num[0];
	for (int i = 0; i < tam-1; i++)
	{
		if (min > num[i])
		{
			for (int j = i+1; j < tam; j++)
			{
				if (min > num[i])
				{
					min = j;
				}

			}

			aux = num[i];
			num[i] = num[min];
			num[min] = aux;

		}
	}
}