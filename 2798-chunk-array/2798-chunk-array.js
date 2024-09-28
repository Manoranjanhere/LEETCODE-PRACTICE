/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    const array=[];
    for(let i=0;i<arr.length;i+=size)
    {
        array.push(arr.slice(i,i+size));
    }
    return array;
};
