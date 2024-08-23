/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var a =init;
   
    function increment()
    {
       return ++a;
    }
    function decrement()
    {
       return --a;
    }
    function reset()
    {
        return a=init;
    }
    return {increment,decrement,reset};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */