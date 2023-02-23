/**
* shell_sort - sorts an array of integers in ascending order using the
*              Shell sort algorithm, using the Knuth sequence
*
* @array: Pointer to the array to sort
* @size:  Size of the array
*/
void shell_sort(int *array, size_t size)
{
size_t gap = 1, i, j;
int tmp;

/* Calculate the initial gap */
while (gap < size)
{
gap = gap * 3 + 1;
}

while (gap > 0)
{
/* Do the insertion sort for the current gap */
for (i = gap; i < size; i++)
{
tmp = array[i];

for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
{
array[j] = array[j - gap];
}

array[j] = tmp;
}

/* Calculate the next gap and print the array */
gap = (gap - 1) / 3;

if (gap % 4 == 0 && gap > 0)
{
printf("Array after sorting with gap %lu: ", gap);
print_array(array, size);
}
}
}
