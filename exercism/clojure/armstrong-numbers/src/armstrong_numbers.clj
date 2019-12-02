(ns armstrong-numbers)
(:require [clojure.string :as str]))

(defn armstrong? [num]
  (let [num-as-str (str num)
      length (count num-as-str)] (
        (defn perchar [char]
          ()
        )
        (reduce perchar "" num-as-str)
      ))
)
