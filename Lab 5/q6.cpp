#include <iostream>
using namespace std;

class GraphicsEngine{
    public:
    void render(){
        cout << "Handles rendering of visuals"<<endl;
    }
};
class InputHandler{
    public:
    void processinput(){
        cout << "Processes user input" <<endl;
    }
};
class PhysicsEngine{
    public:
    void updatephysicsengine(){
        cout << "Manages Physics Calculation" <<endl;
    }
};
class GameEngine{
    GraphicsEngine g;
    InputHandler i;
    PhysicsEngine p;
    public:
    void start(){
        cout << "Game is started" << endl;
        g.render();
        i.processinput();
        p.updatephysicsengine();
    }
    void stop(){
        cout << "Game is stoped" << endl;
    }

};

int main(){
    {
        GameEngine g1;
        g1.start();
    }
    cout << "GameEngine object no longer exists " <<endl;
    return 0;
}