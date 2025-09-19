
class Spreadsheet {
public:
    vector<vector<int>> sheet;

    Spreadsheet(int rows) {
        sheet = vector<vector<int>>(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        char c = cell[0];
        int r = stoi(cell.substr(1)) - 1; // convert to 0-based index
        if (r >= 0 && r < sheet.size()) {
            sheet[r][c - 'A'] = value;
        }
    }

    void resetCell(string cell) {
        char c = cell[0];
        int r = stoi(cell.substr(1)) - 1;
        if (r >= 0 && r < sheet.size()) {
            sheet[r][c - 'A'] = 0;
        }
    }

    int getValue(string formula) {
        formula = formula.substr(1); // remove '='
        int pos = formula.find('+');
        string a = formula.substr(0, pos);
        string b = formula.substr(pos + 1);

        auto getVal = [&](string t) -> int {
            if (isdigit(t[0])) {
                return stoi(t); // number
            } else {
                char c = t[0];
                int r = stoi(t.substr(1)) - 1;
                if (r >= 0 && r < sheet.size()) {
                    return sheet[r][c - 'A'];
                }
                return 0; // out of range -> treat as 0
            }
        };

        int v1 = getVal(a);
        int v2 = getVal(b);

        return v1 + v2;
    }
};
