#include "Subject.h"

namespace m5_mytool {

void Subject::Add(Listener& listener){

    /* check if there is a matching element */
    auto it = bodies_.begin();
    while(it != bodies_.end()){
        if(it->lock() == listener.body()){
            break;   
        }
        ++it;
    }
    if(it == bodies_.end()){
        bodies_.push_back(listener.body());
    }
}

void Subject::Detete(Listener& listener){
    for(auto it = bodies_.begin(); it != bodies_.end(); it++){
        if(it->lock() == listener.body()){
            bodies_.erase(it);
            break;
        }
    }
}

void Subject::Notify(){

    Sweep(); /* sweep unreferenced pointer, before calling handler. */

    // Serial.print(bodies_.size());
    for(auto& w: bodies_){
        w.lock()->Update(this);
    }
}

void Subject::Sweep(){
    for(auto it = bodies_.begin(); it != bodies_.end();){
        if(it->expired()){
            it=bodies_.erase(it);
        }else{
            ++it;
        }
    }
}

} // namespace