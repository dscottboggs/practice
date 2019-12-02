var applesHit = 0
    var orangesHit = 0
    for(apple in apples){
        if( t>=(a+apple) && (a+apple)>=s ){
            applesHit++
        }
    }
    for (orange in oranges){
        if( s <= (b-orange) && (b-orange) <= t ){
            orangesHit++
        }
    }
    println("$applesHit\n$orangesHit")
