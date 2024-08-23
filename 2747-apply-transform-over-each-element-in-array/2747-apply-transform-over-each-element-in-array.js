/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let newarr=[];
    arr.forEach((it,ind)=>newarr.push(fn(it,ind)));
    return newarr;
};