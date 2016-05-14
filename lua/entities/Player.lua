local Player = {}

function Player.new(pos)
    local self = {}
    self.id = "Player"
    self.Renderable = {
        zValue = 0
    }
    self.Animator = {
        position = {-3.5, -4.5},
        animations = {
            {"Standing", "rainsford.lua"},
            {"Running", "rainsford.lua"},
            {"Jumping", "rainsford.lua"},
            {"Death", "rainsford.lua"},
            {"Crouching", "rainsford.lua"},
            {"Crawling", "rainsford.lua"}
        }
    }
    self.Spatial = {
        position = {0, 0},
        origin = {0, 0}
    }
    self.Physical = {
        b2BodyDef = {
            position = pos,
            fixedRotation = true;
            type = "b2_dynamicBody"
        },
        b2FixtureDef = {
            density = 1.0,
            friction = 1,
            restitution = 0.0,
            b2PolygonShape = {
                setAsBox = {0.8, 1.8}
            }
        }
    }
    self.Scriptable = {
        {
            script = "playerControl"
        }
    }
    return self
end

return Player