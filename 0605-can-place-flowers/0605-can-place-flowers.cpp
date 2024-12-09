class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int m = flowerbed.size();
        
        if (m == 1) {
            if (flowerbed[0] == 0) count++;
            return n <= count;
        }

        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            count++;
        }
        for (int i = 1; i < flowerbed.size() - 1; i++) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                count++;
            } 
        }
        if (flowerbed[m - 1] == 0 && flowerbed[m - 2] == 0) {
            count++;
        }
        //cout << count << endl;
        //for (int flower: flowerbed) cout << flower << endl;
        return n <= count;
    }
};