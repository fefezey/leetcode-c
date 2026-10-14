
int maxProfit(int* prices, int pricesSize)
{
    int minPrice = prices[0];
    int maxProfit = 0;
    int i = 1;

    while (i < pricesSize)
    {
        if (prices[i] < minPrice)
            minPrice = prices[i];

        if (prices[i] - minPrice > maxProfit)
            maxProfit = prices[i] - minPrice;

        i++;
    }

    return maxProfit;
}
