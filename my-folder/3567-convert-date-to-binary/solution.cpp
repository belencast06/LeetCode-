class Solution {
public:
    string convertDateToBinary(string date) {
       int yearStr=stoi(date.substr(0,4));
       int monthStr=stoi(date.substr(5,2));
       int dayStr=stoi(date.substr(8,2));
       string year="";
       string month="";
       string day="";

       while(yearStr!=0){
         year=to_string(yearStr%2)+year;
         yearStr=yearStr/2;
       }

       while(monthStr!=0){
        month=to_string(monthStr%2)+month;
         monthStr=monthStr/2;
       }

        while(dayStr!=0){
         day=to_string(dayStr%2)+day;
         dayStr=dayStr/2;
        }

    return year+"-"+month+"-"+day;
    }
};
