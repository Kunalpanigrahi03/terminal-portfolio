const IS_DEV = /localhost|127\.0\.0\.1|\.netlify\.app|\.vercel\.app/.test(window.location.hostname);
const CSS_PATH = IS_DEV ? "tui.css" : "tui.min.css";
const JS_PATH = IS_DEV ? "tui.js" : "tui.min.js";

function loadDependency(e, t, n) {
    let s = document.head,
        c = document.getElementById("min-style"),
        i = "script" === t ? document.createElement("script") : document.createElement("link");
    
    "script" === t ? (
        i.type = "text/javascript",
        i.src = e
    ) : (
        i.rel = "stylesheet",
        i.href = e
    );
    
    "script" === t && null != n && (
        i.onreadystatechange = n,
        i.onload = n
    );
    
    s.appendChild(i);
    c?.remove();
}

loadDependency(CSS_PATH, "link");
loadDependency(JS_PATH, "script", function() {
    init();
});