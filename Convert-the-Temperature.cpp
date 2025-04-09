class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kelvin, fahren;
        vector<double> ans;
        kelvin= celsius+273.15;
        fahren= celsius*1.80+32;
        ans.push_back(kelvin);
        ans.push_back(fahren);
        return ans;
    }
};