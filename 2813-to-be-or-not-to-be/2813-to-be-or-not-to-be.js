/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return{
    toBe: function(val2)
    {
        if(val2!==val)
        {
            throw new Error("Not Equal");
        }
        else
        {
            return true
        }
    },
    notToBe: function(val2)
    {
        if(val===val2)
        {
            throw new Error("Equal");
        }
        else
        {
            return true;
        }
    }
    }

};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */