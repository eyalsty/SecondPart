#include "BFS.h"

std::vector<MyState *> BFS::search(Searchable *searchable) {
    std::queue<MyState *> q;
    std::vector<MyState *> adj;
    MyState *s;
    s = searchable->getInitialState();
    s->setMinPath(0);
    s->setColor(grey);
    q.push(s);
    while (!q.empty()) {
        s = q.front();
        q.pop();
        if(searchable->isGoalState(*s)){
            // returning the path to the goal node.
            return traceBack(s);
        }
        adj = searchable->getAllPossibleStates(*s);
        for (auto &v : adj) {
            if (v->getColor() == white) {
                v->setColor(grey);
                v->setCameFrom(s);
                v->setMinPath(s->getMinPath() + v->getEdgeCost());
                q.push(v);
            }
        }
        s->setColor(black);
        ++evaluatedNodes;
    }
}