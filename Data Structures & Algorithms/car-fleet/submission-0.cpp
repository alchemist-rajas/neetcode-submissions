class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n =  position.size();
        vector<pair<int,double>> cars(n);

        for(int i =0; i < n; i++){
            double timeToTarget = (double)(target-position[i])/speed[i];
            cars[i] = {position[i],timeToTarget};
        }

        sort(cars.begin(),cars.end());

        int fleets=0;
        double maxTime = 0;

        for(int i  = n -1 ; i >= 0 ; i--) {
            if( cars[i].second >  maxTime) {
                fleets++;
                maxTime = cars[i].second;
            }
        }

        return fleets;
    }
    
};
