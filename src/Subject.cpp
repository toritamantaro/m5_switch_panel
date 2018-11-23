#include "Subject.h"

namespace m5_mytool {

void Subject::add_listener(Listener& l){

    /* check if there is a matching element */
    auto it = lbs_.begin();
    while(it != lbs_.end()){
        if(it->lock() == l.handler()){
            break;   
        }
        ++it;
    }
    if(it == lbs_.end()){
        lbs_.push_back(l.handler());
    }
}

void Subject::detete_listener(Listener& l){
    for(auto it = lbs_.begin(); it != lbs_.end(); it++){
        if(it->lock() == l.handler()){
            lbs_.erase(it);
            break;
        }
    }
}

void Subject::notify(){

    sweep(); /* sweep unreferenced pointer, before calling handler. */

    //Serial.print(lbs_.size());
    for(auto& w: lbs_){
        w.lock()->update(this);
    }
}

void Subject::sweep(){
    for(auto it = lbs_.begin(); it != lbs_.end();){
        if(it->expired()){
            it=lbs_.erase(it);
        }else{
            ++it;
        }
    }
}

} // namespace