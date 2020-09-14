class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        costs_arr = copy.copy(costs)
        for i in range(len(costs_arr)):
            costs_arr[i].append(abs(costs[i][0] - costs[i][1]))
        costs_arr = sorted(costs_arr, key=lambda item : item[2], reverse=True)
        total_cost, city_a, city_b = 0,0,0
        for city in costs_arr:
            if city[0] < city[1] and city_a < len(costs) / 2:
                total_cost += city[0]
                city_a += 1
            elif city[0] < city[1]:
                total_cost += city[1]
                city_b += 1
            elif city[1] < city[0] and city_b < len(costs) / 2:
                total_cost += city[1]
                city_b += 1
            else:
                total_cost += city[0]
                city_a += 1
        return total_cost
