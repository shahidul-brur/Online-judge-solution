/**
    case:
    [-3, -5, -8, -4, -10]
*/

int solution(vector<int> &a) {
    int n = a.size();
    int min_idx = 0, continuous_start = 0;
    float min_avg = (a[0]+a[1])/2.0, continuous_avg = min_avg;
    for(int i = 2;i<n;i++){
        continuous_avg = (continuous_avg*(i-continuous_start) + a[i]) / (i-continuous_start+1);
        if ((a[i-1]+a[i])/2.0 < continuous_avg){
            continuous_avg = (a[i-1]+a[i])/2.0;
            continuous_start = i-1;
        }
        if (continuous_avg < min_avg){
            min_avg = continuous_avg;
            min_idx = continuous_start;
        }
    }
    return min_idx;
}


/**
    wrong attempts
*/
// 70%, for the input [-3, -5, -8, -4, -10] the solution returned a wrong answer (got 3 expected 2).
int solution(vector<int> &a) {
    float min_avg = (a[0] + a[1])/2.0;
    int min_idx = 0, amount = 2, cur_start = 0;
    int n = a.size();
    for(int i=2;i<n;i++){
        if (cur_start + amount == i && a[i] <= min_avg){
            if (cur_start + amount == i && a[i] < min_avg){
                min_idx = cur_start;
            }
            min_avg = (min_avg*amount + a[i])/(amount+1);
            amount++;
        }
        if ((a[i-1]+a[i])/2.0 <= min_avg){
            if ((a[i-1]+a[i])/2.0 < min_avg){
                min_idx = i-1;
            }
            min_avg = (a[i-1]+a[i])/2.0;
            amount=2;
            cur_start = i-1;
        }
    }
    return min_idx;
}

// 50%, for the input [10, 10, -1, 2, 4, -1, 2, -1] the solution returned a wrong answer (got 2 expected 5).
int solution(vector<int> &a) {
    float min_avg = (a[0] + a[1])/2.0;
    int min_idx = 0;
    float sum = a[0]+a[1];
    int start_idx = 0;
    int n = a.size();
    for(int i=2;i<n;i++){
        // cout << i << ": \n..............\n";
        // cout << "sum: " << sum << "\n";
        // cout << "start_idx: " << start_idx << "\n";
        //  cout << "min_avg: " << min_avg << "\n";
        // cout << "continue: " << (sum+a[i])/(i-start_idx+1) << "\n";
        float prev = sum;
        if ((sum+a[i])/(i-start_idx+1)<=min_avg){
            min_avg = (sum+a[i])/(i-start_idx+1);
            min_idx = start_idx;
            sum+=a[i];
        }
        // cout << "continue less eq? " << ((sum+a[i])/(i-start_idx+1)<=min_avg) << "\n";
        // cout << "start: " << (a[i-1]+a[i])/2.0 << "\n";
        if ((a[i-1]+a[i])/2.0 < (prev+a[i])/(i-start_idx+1)){
            start_idx = i-1;
            sum = a[i-1]+a[i];
        }
        if ((a[i-1]+a[i])/2.0 < min_avg){
            min_avg = (a[i-1]+a[i])/2.0;
            min_idx = i-1;
        }
        // cout << "min avg: " << min_avg <<  "\n";
        // cout << "min idx: " <<  min_idx <<  "\n";
    }
    return min_idx;
}

// 10%, for the input [-3, -5, -8, -4, -10] the solution returned a wrong answer (got 0 expected 2).

int solution(vector<int> &a) {
    float min_avg = a[0] + a[1];
    int min_idx = 0;
    float sum = a[0];
    int start_idx = 0;
    int n = a.size();
    for(int i=1;i<n;i++){
        // cout << i << ": \n..............\n";
        // cout << "sum: " << sum << "\n";
        // cout << "start_idx: " << start_idx << "\n";
        // cout << "continue: " << (sum+a[i])/(i-start_idx+1) << "\n";
        if ((sum+a[i])/(i-start_idx+1)<min_avg){
            min_avg = (sum+a[i])/(i-start_idx+1);
            sum+=a[i];
        }
        else {
            sum = a[i];
            start_idx = i;
        }
        // cout << "start: " << (a[i-1]+a[i])/2.0 << "\n";
        if ((a[i-1]+a[i])/2.0 < min_avg){
            min_avg = (a[i-1]+a[i])/2.0;
            min_idx = i-1;
            start_idx = i-1;
            sum = a[i-1]+a[i];
        }
        // cout << "min avg: " << min_avg <<  "\n";
        // cout << "min idx: " <<  min_idx <<  "\n";
    }
    return min_idx;
}

// 30%, for the input [-3, -5, -8, -4, -10] the solution returned a wrong answer (got 0 expected 2).
int solution(vector<int> &a) {
    float min_avg = a[0] + a[1];
    int min_idx = 0;
    float sum = a[0];
    int start_idx = 0;
    int n = a.size();
    for(int i=1;i<n;i++){
        // cout << i << ": \n..............\n";
        // cout << "sum: " << sum << "\n";
        // cout << "start_idx: " << start_idx << "\n";
        // cout << "continue: " << (sum+a[i])/(i-start_idx+1) << "\n";
        if ((sum+a[i])/(i-start_idx+1)<=min_avg){
            min_avg = (sum+a[i])/(i-start_idx+1);
            sum+=a[i];
        }
        // cout << "start: " << (a[i-1]+a[i])/2.0 << "\n";
        if ((a[i-1]+a[i])/2.0 < min_avg){
            min_avg = (a[i-1]+a[i])/2.0;
            min_idx = i-1;
            start_idx = i-1;
            sum = a[i-1]+a[i];
        }
        // cout << "min avg: " << min_avg <<  "\n";
        // cout << "min idx: " <<  min_idx <<  "\n";
    }
    return min_idx;
}

// 30%, for the input [-3, -5, -8, -4, -10] the solution returned a wrong answer (got 0 expected 2).

int solution(vector<int> &a) {
    float min_avg = a[0] + a[1];
    int min_idx = 0;
    float sum = a[0];
    int start_idx = 0;
    int n = a.size();
    for(int i=1;i<n;i++){
        // cout << i << ": \n..............\n";
        // cout << "sum: " << sum << "\n";
        // cout << "start_idx: " << start_idx << "\n";
        // cout << "continue: " << (sum+a[i])/(i-start_idx+1) << "\n";
        if ((sum+a[i])/(i-start_idx+1)<min_avg){
            min_avg = (sum+a[i])/(i-start_idx+1);
            sum+=a[i];
        }
        // cout << "start: " << (a[i-1]+a[i])/2.0 << "\n";
        if ((a[i-1]+a[i])/2.0 < min_avg){
            min_avg = (a[i-1]+a[i])/2.0;
            min_idx = i-1;
            start_idx = i-1;
            sum = a[i-1]+a[i];
        }
        // cout << "min avg: " << min_avg <<  "\n";
        // cout << "min idx: " <<  min_idx <<  "\n";
    }
    return min_idx;
}
