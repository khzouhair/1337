size_t	fft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	lendest;
	size_t	lensrc;
	size_t	i;

	lensrc = ft_strlen(src);
	if (dstsize == 0)
		return (lensrc);
	if (dstsize>0)
		{

	i = 0;
	lendest = ft_strlen(dest);
	while (src[i] && i < dstsize - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
		}
	return (lensrc);
}