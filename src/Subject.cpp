#include "Subject.h"

namespace m5_mytool {

void Subject::add_listener(std::shared_ptr<Listener> lsn){

    /* check if there is a matching element */
    auto it = listeners_.begin();
    while(it != listeners_.end()){
        if(it->lock() == lsn){
            break;   
        }
        ++it;
    }
    if(it == listeners_.end()){
        listeners_.push_back(lsn);
    }
}

void Subject::detete_listener(std::shared_ptr<Listener> lsn){
    for(auto it = listeners_.begin(); it != listeners_.end(); it++){
        if(it->lock() == lsn){
            listeners_.erase(it);
            break;
        }
    }
}

void Subject::notify(){

    sweep(); /* sweep unreferenced pointer, before calling handler. */

    //Serial.print(listeners_.size());
    for(auto& w: listeners_){
        w.lock()->update(this);
    }
}

void Subject::sweep(){
    for(auto it = listeners_.begin(); it != listeners_.end();){
        if(it->expired()){
            it=listeners_.erase(it);
        }else{
            ++it;
        }
    }
}

} // namespace