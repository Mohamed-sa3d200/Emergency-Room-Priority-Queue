#include <bits/stdc++.h>
using namespace std;

// Class representing a PATIENT with name, priority, and arrival time
class PATIENT {
public:
    string N_ME;
    int PROI;
    int TIME_IDE;

    static int COUNTER;

    PATIENT(string NA, int PAT) {
        N_ME = NA;
        PROI = PAT;
        TIME_IDE = COUNTER++;
    }

    PATIENT() {
        N_ME = "";
        PROI = 0;
        TIME_IDE = COUNTER++;
    }

    void DISPLAY() const {
        cout << "Name: " << N_ME
             << ", Priority: " << PROI
             << ", Arrival Time: " << TIME_IDE << endl;
    }

    // Compare based on priority, then arrival time
    bool operator>(const PATIENT& OBJ) const {
        if (PROI > OBJ.PROI) {
            return true;
        } 
        else if (PROI == OBJ.PROI) {
            return TIME_IDE < OBJ.TIME_IDE;
        } 
        else {
            return false;
        }
    }
};

int PATIENT::COUNTER = 0;

// MAXHEAP to manage PATIENTs
class MAXHEAP {
private:
    PATIENT* HEAP;
    int CAPA;
    int SZE;

    int PARENT(int x) { return (x - 1) / 2; }
    int L_CHILD(int x) { return 2 * x + 1; }
    int R_CHILD(int x) { return 2 * x + 2; }

    void SWAP(PATIENT& OBJ, PATIENT& OBJ2) {
        PATIENT TMP = OBJ;
        OBJ = OBJ2;
        OBJ2 = TMP;
    }

    void HEAPIFY_UP(int IDX) {
        while (IDX > 0 && HEAP[IDX] > HEAP[PARENT(IDX)]) {
            SWAP(HEAP[IDX], HEAP[PARENT(IDX)]);
            IDX = PARENT(IDX);
        }
    }

    void HEAPIFY_DOWN(int IDX) {
        while (1) {
            int MAX = IDX;
            int L_FT = L_CHILD(IDX);
            int R_GHT = R_CHILD(IDX);

            if (L_FT < SZE && HEAP[L_FT] > HEAP[MAX]){MAX = L_FT;}
                
            if (R_GHT < SZE && HEAP[R_GHT] > HEAP[MAX]){MAX = R_GHT;}

            if (MAX == IDX){break;}

            SWAP(HEAP[IDX], HEAP[MAX]);
            IDX = MAX;
        }
    }

    void RESIZE() {
        CAPA *= 2;
        PATIENT* NEW_HEAP = new PATIENT[CAPA];

        for (int i = 0; i < SZE;i++){NEW_HEAP[i] = HEAP[i];}
            
        delete[] HEAP;
        HEAP = NEW_HEAP;
    }

public:
    MAXHEAP(int INIT_CAPA = 100) {
        CAPA = INIT_CAPA;
        HEAP = new PATIENT[CAPA];
        SZE = 0;
    }

    ~MAXHEAP() {
        delete[] HEAP;
    }

    void INSERT(const PATIENT& OBJ) {
        if (SZE == CAPA)
            RESIZE();
        HEAP[SZE] = OBJ;
        HEAPIFY_UP(SZE);
        SZE++;
    }

    PATIENT EXTRACT_MAX_PATIENT() {
        if (SZE == 0)
            throw runtime_error("HEAP HAS NO ELEMENTS!");

        PATIENT _PATI = HEAP[0];
        HEAP[0] = HEAP[SZE - 1];
        SZE--;
        HEAPIFY_DOWN(0);
        return _PATI;
    }

    PATIENT PEEK() {
        if (SZE == 0)
            throw runtime_error("HEAP HAS NO ELEMENTS!");
        return HEAP[0];
    }

    void PRINT_HEAP() {
        cout << "*** Current Heap ***\n";
        for (int i = 0; i < SZE;i++) {
            HEAP[i].DISPLAY();
        }
        cout << "**********************\n";
    }

    bool IS_EMPTY() const {
        return SZE == 0;
    }
};

int main() {
    MAXHEAP HEAP;
    PATIENT::COUNTER = 1;

    int CH;
    cout << "Choose input method:\n";
    cout << "1. Read From External File\n";
    cout << "2. Enter by Keyboard\n";
    cout << "Enter your Choice: ";
    cin >> CH;

    if (CH == 1) {
        // File input
        ifstream F_NAME("input.txt");
        if (!F_NAME.is_open()) {
            cerr << "Failed To Open This File." << endl;
            return 1;
        }

        string N_ME;
        int PROIA;
        while (F_NAME >> N_ME >> PROIA) {
            PATIENT OBJ(N_ME, PROIA);
            HEAP.INSERT(OBJ);
        }

        F_NAME.close();
    } 
    else if (CH == 2) {
        // Manual input
        int SUM;
        cout << "Enter Number Of Patients: ";
        cin >> SUM;
        for (int i = 0; i < SUM;i++) {
            string N_ME;
            int PROIA;
            cout << "Enter name and priority for PATIENT " << (i + 1) << ": ";
            cin >> N_ME >> PROIA;
            HEAP.INSERT(PATIENT(N_ME, PROIA));
        }
    } 
    else {
        cout << "Invalid Input Please, Try Again.\n";
        return 1;
    }

    // Show heap after input
    cout << "\nHeap After Insertion:\n";
    HEAP.PRINT_HEAP();

    // PEEK at the top Patient
    cout << "\nPeek At The Top Patient:\n";
    HEAP.PEEK().DISPLAY();

    // Extract top Patient
    cout << "\nExtracting The Top Patient:\n";
    PATIENT EXTRACT_PATIENT = HEAP.EXTRACT_MAX_PATIENT();
    EXTRACT_PATIENT.DISPLAY();

    // Heap after one extraction
    cout << "\nHeap After Extraction:\n";
    HEAP.PRINT_HEAP();

    // Extract and print all Patient
    cout << "\nExtracting All Patients:\n";
    while (!HEAP.IS_EMPTY()) {
        PATIENT EXTRA = HEAP.EXTRACT_MAX_PATIENT();
        EXTRA.DISPLAY();
    }

    return 0;
}
