d3.csv('../../data/BOOK.csv')
    .then(function(data) {
        console.group('图书信息')
        const BOOK = new Array(data.length)
        for (let i = 0; i < data.length; i++) {
            var len = [];
            len.push(data[i].ISBN)
            len.push(data[i].name)
            len.push(data[i].author)
            len.push(data[i].press)
            len.push(data[i].price)
            len.push(data[i].sum)
            BOOK[i] = len
        }
        // console.log(JSON.stringify(Major));
        console.log(data);
        console.log(BOOK);
        const ts1 = d3.select("ts1")
        const g = d3.select("#g3")
        for (let i = 0; i < data.length; i++) {
            g.append('text')
                .attr('y', 50 + (i - 1) * 30)
                .attr('x', 0)
                .attr('fill', '#c23531')
                .text('(' + (i + 1) + ')') <
                g.append('text')
                .attr('y', 50 + (i - 1) * 30)
                .attr('x', 30)
                .attr('fill', '#c23531')
                .text("ISBN:" + BOOK[i][0])
            g.append('text')
                .attr('y', 50 + (i - 1) * 30)
                .attr('x', 120)
                .attr('fill', '#c23531')
                .text("书名:" + BOOK[i][1])
            g.append('text')
                .attr('y', 50 + (i - 1) * 30)
                .attr('x', 210)
                .attr('fill', '#c23531')
                .text("作者:" + BOOK[i][2])
            g.append('text')
                .attr('y', 50 + (i - 1) * 30)
                .attr('x', 300)
                .attr('fill', '#c23531')
                .text("出版社:" + BOOK[i][3])
            g.append('text')
                .attr('y', 50 + (i - 1) * 30)
                .attr('x', 390)
                .attr('fill', '#c23531')
                .text("价格:" + BOOK[i][4])
            g.append('text')
                .attr('y', 50 + (i - 1) * 30)
                .attr('x', 480)
                .attr('fill', '#c23531')
                .text("数量:" + BOOK[i][5])
        }
    })