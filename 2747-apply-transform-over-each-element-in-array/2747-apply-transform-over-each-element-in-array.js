/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let newarr=[];
    arr.forEach((it,index)=>newarr.push(fn(it,index)));
    return newarr;
};