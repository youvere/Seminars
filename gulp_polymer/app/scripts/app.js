(function(document) {
    'use strict';

    var app = document.querySelector('#app');
    app.target = document.body;

    window.addEventListener('WebComponentsReady', function() {
    });

    app.addEventListener('dom-change', function() {
    });

    app.next = function () {
        app.entryAnimation = app.nextEntryAnimation;
        app.exitAnimation = app.nextExitAnimation;

        page(app.nextPage);
    };

    app.previous = function () {
        app.entryAnimation = app.previousEntryAnimation;
        app.exitAnimation = app.previousExitAnimation;

        page(app.previousPage);
    };
})(document);
