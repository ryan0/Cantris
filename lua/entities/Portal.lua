--
-- Created by IntelliJ IDEA.
-- User: Ryan
-- Date: 5/9/2016
-- Time: 10:15 PM
-- To change this template use File | Settings | File Templates.
--

local Portal = {}

function Portal.new(id, targetId)
    local self = {}
    self.id = id
    self.Renderable = {
        zValue = -1
    }
    self.Animator = {
        animations = {
            {"Portal1", "plantPortal.lua"},
            {"Portal1Reverse", "plantPortal.lua"}
        }

    }
    self.Spatial = {
        position = {0, 0}
    }
    self.Scriptable = {
        {
            script = "gate",
            parameters = targetId
        }
    }
    return self
end

return Portal

