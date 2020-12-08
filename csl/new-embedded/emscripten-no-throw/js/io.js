mergeInto(LibraryManager.library, {
    web_async_read: function () {
        return Asyncify.handleAsync(async () => {
            out("waiting for input");
            //const char = await read_char_promise();
            // out(char);
            //return char;
            return 0;
        });
    },
    web_async_write: function (char) {
        // console.log('async write called: ')
        out(`write called: ${char}`);
        //outputBuf.push(char);
        //if (intArrayToString([char]) === '\n') {
        //    term.write(outputBuf);
        //    outputBuf = [];
        //}
        return 0;
    },
    web_async_info_write: function (char) {
        out(`read char: ${char}, ${intArrayToString([char])}`);
        return 0;
    }
});