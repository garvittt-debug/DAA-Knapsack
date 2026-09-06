//garvitgangwar 25/Da/027
#include <iostream>
using namespace std;

struct Item
{
    int weight;
    int profit;
    float ratio;
};

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item item[100];

    cout << "Enter weight and profit of each item:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> item[i].weight >> item[i].profit;

        item[i].ratio =
            (float)item[i].profit / item[i].weight;
    }

    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    // Sort according to profit/weight ratio
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (item[i].ratio < item[j].ratio)
            {
                Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    float totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        if (capacity >= item[i].weight)
        {
            capacity = capacity - item[i].weight;
            totalProfit = totalProfit + item[i].profit;
        }
        else
        {
            totalProfit =
                totalProfit + item[i].ratio * capacity;

            capacity = 0;
            break;
        }
    }

    cout << "Maximum Profit = " << totalProfit;

    return 0;
}
