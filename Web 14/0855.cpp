#include <set>
using namespace std;

class ExamRoom {
private:
    int n;          // количество мест
    set<int> seats;  // занятые места

public:
    ExamRoom(int n) : n(n) {}

    int seat() {
        if (!seats.size()) {
            seats.insert(0);
            return 0;
        }
        
        int max_dist = -1;
        int best_seat = 0;
        
        auto first = seats.begin();
        if (*first > 0) {            
            if (*first > max_dist) {
                max_dist = *first;                
            }
        }
        for(auto current = seats.begin(), next_seat = next(current, 1);
            next_seat!= seats.end();
            current++, next_seat++){
            int dist = (*next_seat - *current) / 2;
            if (dist > max_dist) {
                max_dist = dist;
                best_seat = *current + dist;
            }
        }

        auto last = seats.rbegin();
        if (*last < n - 1 - max_dist) {            
            best_seat = n - 1;
        }      

        seats.insert(best_seat);
        return best_seat;
    }

    void leave(int p) {
        seats.erase(p);
    }
};

int main(){
    ExamRoom r(10);
    r.seat();
    r.seat();
    r.seat();
    r.seat();
    return 0;
}