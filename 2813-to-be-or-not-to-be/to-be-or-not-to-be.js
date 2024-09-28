/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe: (val1) => {
            try {
                if(val === val1) {
                    return true;
                }
                throw new Error("Not Equal");
            } catch(err) {
                throw new Error("Not Equal");
            }
        },
        notToBe: (val1) => {
            try {
                if(val !== val1) {
                    return true;
                }
                throw new Error("Equal");
            } catch(err) {
                throw new Error("Equal");
            }
        },
    }
};


/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */