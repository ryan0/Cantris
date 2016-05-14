--
-- Created by IntelliJ IDEA.
-- User: Ryan
-- Date: 5/9/2016
-- Time: 7:18 PM
-- To change this template use File | Settings | File Templates.
--

local ScrollingImage = {}

function ScrollingImage.new(scrollRate, file, pos, scl, layer)
    local self = {}
    self.Renderable = {
        zValue = layer
    }
    self.Graphical = {
        texture = file,
        scale = scl
    }
    self.Spatial = {
        position = pos
    }
    self.Scriptable = {
        {
            script = "scrolling",
            parameters = scrollRate
        }
    }
    return self
end

return ScrollingImage

