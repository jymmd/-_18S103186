#include<iostream>
#include<string>
#include<vector>

using namespace std;

//nclab,18S103186,黄婧垚

//一盘棋类游戏
class Game {
};

//玩家
class Player{
    int playerType;
    string name;
    Action action;
};

//棋盘
class Board{
    int size;
    vector<vector<Piece>> board;
    void initBoard(int bsize) {
        size = bsize;
        Piece piece;
        piece.type = 0;
        vector<vector<Piece>> initboard(size, vector<Piece>(size, piece));
        board = initboard;
    }
};

//棋子
class Piece{
    Player belong;
    Position position;
    int type; //0表示没有棋子，1表示player1的棋子，2表示player2的棋子
    int color;
};

//棋盘上的位置
class Position{
    int xPosition;
    int yPosition;
};

//下棋动作
class Action{
    void putPiece(Board board, Player player){
        //判断位置是否合法,改变一下board信息
        Piece piece;
        piece.Belong = player;
        piece.color = player.playerType;
        vector<vector<int>> gameBoard = board.board;
        int x;
        int y;
        int bsize = board.size;
        int flag = 0;
        cout << "please input position you want to put your piece"<<endl;
        do{
            if(flag == 1) cout << "this postion already have piece, plese re-input positon"<<endl;
            cout << "x position:";
            cin >> x;
            while(x < 0 || x >= bsize) {
                cout << "x input out of range, please re-input";
                cout << "x position:";
                cin >> x;
            }
            cout << "y position:";
            cin >> y;
            while(y < 0 || y >= bsize) {
                cout << "y input out of range, please re-input";
                cout << "y position:";
                cin >> y;
            }
            flag = 1
        }while(gameBoard[x][y].type != 0)
        Position pos;
        pos.xPosition = x;
        pos.yPosition = y;
        piece.position = pos;
        piece.type = player.playerType;
        gameBoard[x][y] = piece;
    }
    void movePiece(Board board, Player player) {
        vector<vector<int>> gameBoard = board.board;
        int x;
        int y;
        int bsize = board.size;
        int flag = 0;
        cout << "please input position you want to move from"<<endl;
        do{
            if(flag == 1) cout << "this postion has no piece or this piece belongs to your opponent, plese re-input positon"<<endl;
            cout << "x position:";
            cin >> x;
            while(x < 0 || x >= bsize) {
                cout << "x input out of range, please re-input";
                cout << "x position:";
                cin >> x;
            }
            cout << "y position:";
            cin >> y;
            while(y < 0 || y >= bsize) {
                cout << "y input out of range, please re-input";
                cout << "y position:";
                cin >> y;
            }
        }while(gameBoard[x][y].type == 0 || gameBoard[x][y].belong != player)
        Piece piece;
        piece.type = 0;
        gameBoard[x][y] = piece;
        cout << "please input position you want to move to"<<endl;
        putPiece(board, player);
    }
    void goKillPiece(Board board, Player player) {
        vector<vector<int>> gameBoard = board.board;
        int x;
        int y;
        int bsize = board.size;
        int flag = 0;
        cout << "please input position you want to move your piece from"<<endl;
        do{
            if(flag == 1) cout << "this postion has no piece or the piece belongs to yourself, plese re-input positon"<<endl;
            cout << "x position:";
            cin >> x;
            while(x < 0 || x >= bsize) {
                cout << "x input out of range, please re-input";
                cout << "x position:";
                cin >> x;
            }
            cout << "y position:";
            cin >> y;
            while(y < 0 || y >= bsize) {
                cout << "y input out of range, please re-input";
                cout << "y position:";
                cin >> y;
            }
        }while(gameBoard[x][y].type == 0 || gameBoard[x][y].belong == player)
        Piece piece;
        piece.type = 0;
        gameBoard[x][y] = piece;
    }
    void chessKillPiece(Board board, Player player) {
        cout << "please input the piece position you want to kill"<<endl;
        goKillPiece(board, player);
        cout << "please input the piece position you want to move"<<endl;
        movePiece(board, player);
    }
    void searchPositon(Board board){
        vector<vector<int>> gameBoard = board.board;
        cout << "please input the position you want to search:" << endl;
        int x;
        int y;
        cout << "x position:";
        cin >> x;
        while(x < 0 || x >= bsize) {
            cout << "x input out of range, please re-input";
            cout << "x position:";
            cin >> x;
        }
        cout << "y position:";
        cin >> y;
        while(y < 0 || y >= bsize) {
            cout << "y input out of range, please re-input";
            cout << "y position:";
            cin >> y;
        }
        type = gameBoard[x][y].type;
        if(type == 0) {
            cout << "idle";
        }else if(type == 1) {
            cout << "occupied by player1";
        }else {
            cout << "occupied by player2";
        }
    }
    void countPiece(Board board){
        vector<vector<int>> gameBoard = board.board;
        int bsize = board.size;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0; i < bsize; i++) {
            for(int j = 0; j < bsize; j++) {
                if(gameBoard[i][j].type == 1) cnt1++;
                else if(gameBoard[i][j].type == 2) cnt2++;
            }
        }
        cout<<"the number of player1 piece:"<<cnt1<<endl;
        cout<<"the number of player2 piece:"<<cnt2<<endl;
    }
};

int main() {
    string gameChoose;
    cout << "choose a game <chess or go>:";
    cin >> gameChoose;
    while(gameChoose != "chess" && gameChoose != "go") {
        cout << "incorrect input, please re-input <chess or go>:";
        cin >> gameChoose;
    }
    Board board;
    if gameChoose == "chess" {
        board.initBoard(8);
    } else {
        board.initBoard(18);
    }

    Player player1;
    player1.playerType = 1;
    Player player2;
    player2.playerType = 2;
    cout << "input name of player1:";
    cin >> player1.name;
    cout << "input name of player2:";
    cin >> player2.name;

    cout << "game begin!"<<endl;

    cout<< "please input your action, you can choose 'end', 'jumpover', 'put', 'move', 'kill', 'search' and 'count'"<<endl;
    string command;
    cin >> command;
    int flag = 1;
    Player *curplayer;
    while(command != "end") {
        if(flag == 1) {
            curplayer = &player1;
        } else {
            curplayer = &player2;
        }
        flag = 0 - flag;
        switch(command) {
            case "jumpover":
                break;
            case "put":
                curplayer.action.putPiece(board, *curplayer);
                break;
            case "move":
                curplayer.action.movePiece(board, *curplayer);
                break;
            case "kill":
                if(gameChoose == "chess") {
                    curplayer.action.chessKillPiece(board, *curplayer);
                }else {
                    curplayer.action.goKillPiece(board, *curplayer);
                }
                break;
            case "search":
                curplayer.action.searchPosition(board);
                break;
            case "count":
                curplayer.action.countPiece(board);
                break;
            default:
                flag = 0 - flag;
                cout << "incorrect input, please re-input" <<endl;
        }
        cout<< "please input your action, you can choose 'end', 'jumpover', 'put', 'move', 'kill', 'search' and 'count'"<<endl;
        cin >> command;
    }
    return 0;
}
