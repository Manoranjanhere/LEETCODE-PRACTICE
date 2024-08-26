/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve,reject)=>
    {
        let count = 0;
        let result = new Array(functions.length)
        for(let i=0;i<functions.length;i++)
        {
            functions[i]().then((data)=>
            {
                count++;
                result[i]=data;
                if(count == functions.length)return resolve(result)
            })            .catch((err) => reject(err))

        }
    })
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */