# game base data

<pre><code>
    baseObject:
	    001. id
	    002. name

    organismObject: baseObject
	    001. life
	    002. lifeMaxLimit
	    003. lifeMinLimit

	
    bodyPart: baseObject
	    001. 
	

    person: organismObject
	    001. emotion（情绪）
	    002. bag (properties) 
	    003. bodyPart(
			[头发，脑，额头，眼睛，脸颊，鼻子，嘴](头部)，
			[颈部]，
			[肩部，锁骨，胸，乳头，肋骨，心脏，肺部，肠胃，肚脐，腰，肾脏](上体)，
			[臂，手，手掌，手指，腿，足，脚趾](四肢)，
			[阴茎，睾丸，前列腺，阴道，子宫，阴核]
		)
	    004. 体力
	    005. 精神
	    006. 饥饿 （食物）
	    007. 饥渴 （水）
	    008. 性别（男，女，无，双）
	    009. 自我称谓

    properties : baseObject
    	001. type(武器，衣物，食物，饮品。。。)
    	002. 拥有者
    	003. 附属位置
    	004. 绝对世界位置
    	005. 影响
    	006.

    action : baseObject
    	001. 释放者
    	002. 接受者
    	003. 作用
    	004. 计数
    
    emotion : baseObject
    	001. 情绪值（整体上来说，0为普通，小于0，则趋向于不好，大于0则趋向于好）
    	002. 描述

</code></pre>










