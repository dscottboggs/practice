
def get_triplet(which)
    returnTriplet = []
    for val in 0..2 do
        print "#{which} triplet item ##{val+1}: "
        returnTriplet.append gets.chomp.to_i
    end
    return returnTriplet
end

aliceTriplet = get_triplet "alice"
bobTriplet = get_triplet "bob"

def get_results(alice, bob)
    ascore, bscore = 0, 0

    for aliceVal, bobVal in alice.zip(bob) do
        if (1 >= aliceVal || aliceVal >= 100) then
            puts "Alice's answer should have been between 1 and 100, inclusive, but it was #{aliceVal}"
        end
        if (1 >= bobVal || bobVal >= 100) then
            puts "Bob's answer should have been between 1 and 100, inclusive, but it was #{bobVal}"
        end
        ascore +=1 if aliceVal>bobVal
        bscore +=1 if aliceVal<bobVal
    end
    return ascore, bscore
end

aliceScore, bobScore = get_results(aliceTriplet, bobTriplet)
puts "#{aliceScore} #{bobScore}"
