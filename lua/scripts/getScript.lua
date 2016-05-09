--
-- Created by IntelliJ IDEA.
-- User: Ryan
-- Date: 5/7/2016
-- Time: 6:08 AM
-- To change this template use File | Settings | File Templates.
--

package.path = package.path .. ';../lua/scripts/?.lua;'

local luaScripts = {
    scriptCount = 0
}

function startScript(scriptHandle, entity, scene)
    luaScripts[scriptHandle]:start(entity, scene)
end

function updateScript(scriptHandle, tpf, entity, scene)
    luaScripts[scriptHandle]:update(tpf, entity, scene)
end

function getScript(scriptName)
    local script = require(scriptName)
    local count = luaScripts.scriptCount
    luaScripts.scriptCount = count + 1
    luaScripts[count] = script.new()
    return count
end